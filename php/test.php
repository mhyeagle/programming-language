<?php
echo str_replace("world", "shanghai", "hello world!");
echo "\n";
echo "***";
echo "<br>";
echo "***";
echo "<br>";

$x = 5;
$y = 10;
$z = $x + $y;
echo $z;
echo "\n";
print "my x: is {$x}\n";
var_dump($x);

class Car
{
    var $color;
    function Car($color = "green") {
        $this->color = $color;
    }

    function what_color() {
        return $this->color;
    }

};

echo strlen("hello");
echo "\n";

echo strpos("hello world", "world");
echo "\n";

#字符串窜接
echo "hello" . " " . "miao" . "\n";


$colors = array("a", "b", "c");
foreach ($colors as $value) {
    echo "$value \n";
}

?>
