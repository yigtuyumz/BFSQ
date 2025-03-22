#!/usr/bin/perl

use warnings;
use strict;

die "program x y density" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

my $empty;
my $wall;
my $fill;

$empty = chr(int(rand(95)) + 32);
$wall = chr(int(rand(95)) + 32);
$fill = chr(int(rand(95)) + 32);

print "$y$empty$wall$fill\n";

for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print "$wall";
		}
		else {
			print "$empty";
		}
	}
	print "\n";
}
