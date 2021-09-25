@echo off

set /p Times=Enter how many times you want to compare: 

cd work

make solve1
make solve2
make constructor
make comparator
make showresult

type nul > ../result.txt

for /l %%t in (1, 1, %Times%) do (
	echo | set /p = Test case %%t:  > tmp.txt
	type nul > data.txt
	type nul > out1.txt
	type nul > out2.txt

	constructor %%t > data.txt
	type data.txt | solve1 > out1.txt
	type data.txt | solve2 > out2.txt

	comparator >> tmp.txt
	type tmp.txt >> ../result.txt
	showresult
)
set /p Times=Press Enter to continue: 
@echo on