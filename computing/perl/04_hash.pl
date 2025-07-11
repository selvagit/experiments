#!/usr/bin/perl

# Modules used
use strict;
use warnings;

# Print function
print("Hashes\n");

#Intializing hash by directly assinging values
my %fruit;
$fruit{'mango'} = 10;
$fruit{'apple'} = 11;

#printing the values
print "$fruit{'mango'}\n";
print "$fruit{'apple'}\n";

# Initializing hash using => 
my %fruit2 = ('mango' => 10, 'apple' => 12); 

print "$fruit2{'mango'}\n";



