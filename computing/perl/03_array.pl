#!/usr/bin/perl

# Modules used
use strict;
use warnings;

# Print function
print("Operator\n");

# define array 
my @array = (1, 2, 3, 4);

# use qw function
my @arr2 = qw /This is a Perl Tutorial/;

# accessing the array elements
print "elements of the array: \n";
print "$array[0]\n";
print "$array[3]\n";

# accessing the array elements
print "elements of the array: \n";
print "$arr2[0]\n";
print "$arr2[1]\n";

# array creation
my @arr3 = (11, 22, 33, 44,55);

# iterating through range
print(" Itertating through the range: \n");

#size of array
my $len = @arr3;

for ($b = 0 ; $b < $len ; $b = $b + 1){ 
    print "\@arr[$b] = $arr3[$b]\n";
}

# Iterating through loops
print ("Iterating through loops: \n ");

foreach $a (@arr3) { print "$a\n"; }
