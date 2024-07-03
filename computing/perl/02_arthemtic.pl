# code is taken from https://www.geeksforgeeks.org/perl-tutorial-learn-perl-with-examples/
#!/usr/bin/perl  
    
# Modules used  
use strict;  
use warnings;  
    
# Print function   
print("Hello World\n"); 

my $a = 10;
my $b = 4;
my $c = "true";
my $d = "false";

# using arithemetic operators
print "Addition is", $a + $b , "\n";
print "Substration is", $a - $b, "\n"; 


# using relational operators
if ($a == $b) {
    print "Equal\n";
}else{
    print "False \n";
}

# using logical operators
my $result = $a && $b ;
print "AND operator:", $result, "\n";

# using Bitwise operators
$result = $a & $b;
print " Bitwise AND:", $result, "\n";

# using the assingment operators
print "Assingment operators:", $a += $b, "\n"; 



