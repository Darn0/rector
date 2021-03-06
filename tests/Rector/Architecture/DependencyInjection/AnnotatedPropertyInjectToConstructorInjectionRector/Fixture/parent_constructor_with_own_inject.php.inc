<?php

namespace Rector\Core\Tests\Rector\Architecture\DependencyInjection\AnnotatedPropertyInjectToConstructorInjectionRector\Fixture;

use DateTimeInterface;
use Rector\Core\Tests\Rector\Architecture\DependencyInjection\ActionInjectionToConstructorInjectionRector\Source\SomeProduct;

class ClassWithInjects8Parent
{
    /**
     * @var DateTimeInterface
     * @inject
     */
    public $dateTime;
}

class ClassWithInjects8 extends ClassWithInjects8Parent
{
    /**
     * @var SomeProduct
     * @inject
     */
    public $property;
}

?>
-----
<?php

namespace Rector\Core\Tests\Rector\Architecture\DependencyInjection\AnnotatedPropertyInjectToConstructorInjectionRector\Fixture;

use DateTimeInterface;
use Rector\Core\Tests\Rector\Architecture\DependencyInjection\ActionInjectionToConstructorInjectionRector\Source\SomeProduct;

class ClassWithInjects8Parent
{
    /**
     * @var DateTimeInterface
     */
    private $dateTime;
    public function __construct(\DateTimeInterface $dateTime)
    {
        $this->dateTime = $dateTime;
    }
}

class ClassWithInjects8 extends ClassWithInjects8Parent
{
    /**
     * @var SomeProduct
     */
    private $property;
    public function __construct(\DateTimeInterface $dateTime, \Rector\Core\Tests\Rector\Architecture\DependencyInjection\ActionInjectionToConstructorInjectionRector\Source\SomeProduct $property)
    {
        $this->property = $property;
        parent::__construct($dateTime);
    }
}

?>
