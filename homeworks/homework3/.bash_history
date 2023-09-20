touch demo.txt
ls
ls -l
which vim
clear
vim demo.txt
pwd
ls
cd cse20133-user
ls
vim demo.txt
ls -l
vim demo.txt
fortune
fortune
which fortune
fortune
export PATH=$PATH:/usr/games
fortune
cowsay "The CSE 20133 students will do great this semester!"
fortune | cowsay | lolcat
fortune | cowsay | lolcat >> demo.txt
fortune | cowsay | lolcat >> demo.txt
cd cse20133-user/
ls
fortune | cowsay | lolcat >> demo.txt
git clone https://github.com/cse20133-f22/cse20133-mmorri22.git
clear
cd cse20133-user/
pwd
git clone https://github.com/cse20133-f22/cse20133-mmorri22.git
cd cse20133-mmorri22/
ls
ls -a
cd ..
clear
pwd
clear
pwd
cd ..
clear
cd cse20133-user/
ls
rm -rf cse20133-mmorri22/
clear
ls
clear
pwd
cd ..
ls
clear
cd cse20133-user/
git clone https://github.com/cse20133-f22/cse20133-mmorri22.git
clear
rm -rf cse20133-mmorri22/
clear
cd ../..
ls
cd home
clear
pwd
cd cse20133-user/
pwd
git clone https://github.com/cse20133-f22/cse20133-mmorri22.git
clear
cd ../..
pwd
ls
cd home
clear
pwd
cd cse20133-user/cse20133-mmorri22/
mkdir reading04
cd reading04
wget https://raw.githubusercontent.com/mmorri22/cse20133/main/readings/reading04/nothing.c
clear
wget https://raw.githubusercontent.com/mmorri22/cse20133/main/readings/lec04/nothing.c
ls -l
clear
gcc nothing.c -o print_nothing 
./print_nothing
ls
ls -l
rm -rf print_nothing 
clear
wget https://raw.githubusercontent.com/mmorri22/cse20133/main/readings/lec04/nothing_2.c
gcc nothing_2.c -o print_nothing_2
./print_nothing_2 
gcc -Wall nothing_2.c -o print_nothing_2
gcc -Wall nothing_2.c -o print_nothing_2
gcc -Wall nothing_2.c -o print_nothing_2
cd cse20133-user/cse20133-mmorri22/
clear
ls
cd reading04
ls
gcc -Wall -Wextra nothing_2.c -o print_nothing 
./print_nothing 
gcc -std=c11 -Wall -Wextra nothing_2.c -o print_nothing 
gcc -std=c2x -Wall -Wextra nothing_2.c -o print_nothing 
gcc -std=c2x -Wall -Wextra nothing_2.c -o print_nothing 
gcc -std=c2x -Wall -Wextra nothing_2.c -o print_nothing 
ls
rm print_nothing 
wget To fix this issue, let's add a return statement. In this case, we will <code>return 0;</code>, which informs the operating systems that the program was successfully completed. This code may be found at <a href="https://raw.githubusercontent.com/mmorri22/cse20133/main/readings/lec04/nothing_3.c">nothing_3.c</a>:

wget https://raw.githubusercontent.com/mmorri22/cse20133/main/readings/lec04/nothing_3.c
gcc -Wall nothing_3.c -o print_nothing
./print_nothing
ls -l
rm print_nothing 
clear
cd ..
ls
clear
pwd
mkdir lec04
ls
cd lec04
touch hello.c
vim hello.c
gcc -Wall -Wconversion -Werror hello.c -o hello
./hello
rm hello
ls
cd ../reading04/
ls
cd ..
ls
ls
git add --all
git commit -m "Lecture 04 Push"
git push -u origin main
ls
cd cse20133-mmorri22/
ls
cd hw0
ls
cd ..
ls
clear
cd lec04
ls
rm *
ls
cd ..
ls
rm -rf lec04
ls
cd ..
ls
ls
cd cse20133-mmorri22/
ls
mkdir lec05
clear
wget https://raw.githubusercontent.com/mmorri22/cse20133/main/inclass/lec05/float_no_compile.c
ls
rm float_no_compile.c 
cd lec05
clear
wget https://raw.githubusercontent.com/mmorri22/cse20133/main/inclass/lec05/float_no_compile.c
clear
gcc -Wall -std=c2x -Wconversion -Werror float_no_compile.c -o float_no_compile
wget https://raw.githubusercontent.com/mmorri22/cse20133/main/inclass/lec05/gangnam.c
gcc -Wall -std=c2x -Wconversion -Werror gangnam.c -o gangnam
./gangnam
wget https://raw.githubusercontent.com/mmorri22/cse20133/main/inclass/lec05/gangnam_long.c
gcc -Wall -std=c2x -Wconversion -Werror gangnam_long.c -o gangnam_long
./gangnam
./gangnam_long
ls
cd ..
ls
clear
ls
clear
ls
clear
ls
clear
ls
cd cse20133-mmorri22/
ls
rm -rf lec07
mkdir lec07
cd lec07
clear
wget https://raw.githubusercontent.com/mmorri22/cse20133/main/inclass/lec07/parallel.c
ls
gcc -std=c2x -g -O2 -Wall -Wextra -Wconversion -Werror parallel.c -o parallel
./parallel
rm -rf parallel
ls
touch parallel_lib.h
touch parallel_lib.c
touch parallel_run.c
clear
ls
gcc -std=c2x -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm -c parallel_run.c
gcc -std=c2x -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm -c parallel_lib.c
gcc -std=c2x -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm -o parallel_run parallel_run.o parallel_lib.o
./parallel_run
clear
ls
rm parallel_run *.o
ls
clear
gcc -std=c2x -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm -c parallel_run.c
ls
gcc -std=c2x -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm -c parallel_lib.c
ls
gcc -std=c2x -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm -o parallel_run
gcc -std=c2x -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm -c parallel_run.c
gcc -std=c2x -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm -c parallel_lib.c
gcc -std=c2x -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm -o parallel_run
ls
rm *.o
ls
touch Makefile
clear
make parallel_lib.o
make parallel_lib.o
rm parallel_lib.o
clear
make parallel_lib.o
make parallel_run.o
rm *.o
ls
make parallel_run
make clean
make parallel_run
./parallel_run
make clean
ls
ls
cd cse20133
cd cse20133-mmorri22/
clear
mkdir lec08
ls
clear
cd lec08
ls
wget https://raw.githubusercontent.com/mmorri22/cse20133/main/inclass/lec08/setup.sh
ls
chmod a+rx setup.sh 
./setup.sh 
ls
ls
rm *
ls
cd ..
ls
clear
pwd
cd lec08
ls
clear
wget https://raw.githubusercontent.com/mmorri22/cse20133/main/inclass/lec08/setup.sh
ls
chmod a+rx setup.sh
ls
./setup.sh 
ls
make fact_double_sci.o
rm fact_double_sci.o
clear
make fact_double_sci.o
make clean
clear
make fact_double_sci
./fact_double_sci
ls
make clean
make all
make clean
ls
clear
touch bird_lib.h bird_lib.c bird_flap.c
ls -l
make bird_flap
make clean
ls
make bird_flap
make bird_flap
make bird_flap
./bird_flap
make clean
ls
make clean
ls
clear
cd ..
ls
cd hw2
clear
make hw2
make Prob1
make Prob3
gcc Prob3.c -lm -o Prob3
./Prob3
make clean
ls
make Prob3
make clean
ls
make Prob3
clear
make Prob3
make clean
make Prob1
make Prob3
make Prob4
make prob5
make Prob5
pwd
cd cse20133-mmorri22/
ls
mkdir lec09
wget https://raw.githubusercontent.com/mmorri22/cse20133/main/inclass/lec09/setup.sh
ls
rm setup.sh 
cd lec09
ls
wget wget https://raw.githubusercontent.com/mmorri22/cse20133/main/inclass/lec09/setup.sh
wget wget https://raw.githubusercontent.com/mmorri22/cse20133/main/inclass/lec09/setup.sh
clear
cd ..
ls
wget wget https://raw.githubusercontent.com/mmorri22/cse20133/main/inclass/lec09/setup.sh
ls
git clone https://github.com/cse20133-f22/cse20133-graceconneely.git
cd cse20133-graceconneely/
cd homework2
ls
make Prob1
./Prob1
make Prob1
./Prob1
make Prob1
./Prob1
make Prob1
./Prob1
make Prob1
./Prob1
make Prob1
./Prob1
make Prob2
./Prob2
make Prob3
./Prob3
make Prob4
./Prob4
make Prob5
./Prob5
make clean
make all
make clean
cd ../..
ls
rm -rf cse20133-graceconneely/
ls
cd cse20133-mmorri22/
ls
mkdir lec11
cd lec11
ls
wget https://raw.githubusercontent.com/mmorri22/cse20133/main/inclass/lec11/setup.sh
chmod a+rx setup.sh 
./setup.sh 
ls
clear
wget https://raw.githubusercontent.com/mmorri22/cse20133/main/inclass/lec11/setup.sh
chmod a+rx setup.sh 
./setup.sh 
ls
rm *.1
ls
make trace
make clean
clear
cd ../lec10
clear
man fscanf
clear
make fscanf
clear
man fscanf
gcc fscanf.c -o fscanf
./fscanf
make fscanf
make fscanf
make clean
cd ../lec11
clear
make trace
make trace_ptr
makeclean
make trace
ls
./trace
clear
make trace
make trace
make trace
clear
./trace
make clean
make trace_ptr
./trace_ptr
make trace_ptr
make trace_ptr
./trace_ptr
make clean
clear
ls
git clone https://github.com/cse20133-f22/cse20133-passaf1.git
cd cse20133-passaf1/
ls
cd homework2
ls
make Prob1
./Prob1
