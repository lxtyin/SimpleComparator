@echo off

set /p Times=Enter how many times you want to compare: 

cd work

g++ ../program1.cpp -o solve1
g++ ../program2.cpp -o solve2
g++ ../generator.cpp -o generator
g++ special_judge.cpp -o checker
g++ render.cpp -o render

type nul > ../result.txt

for /l %%t in (1, 1, %Times%) do (
	echo | set /p = Test case %%t:  
	echo | set /p = Test case %%t:  >> ../result.txt
	type nul > data.txt
	type nul > out1.txt
	type nul > out2.txt

	generator %%t > data.txt
	type data.txt | solve1 > out1.txt
	type data.txt | solve2 > out2.txt

	checker && checker >> ../result.txt
	echo -------------------------------------
	echo ------------------------------------- >> ../result.txt
)
set /p Times=Press Enter to continue: 
@echo on