all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/Nokta.cpp -o ./lib/Nokta.o
	g++ -c -I "./include" ./src/DogruKuyrugu.cpp -o ./lib/DogruKuyrugu.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/AVLAgaci.cpp -o ./lib/AVLAgaci.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++  ./lib/AVLAgaci.o ./lib/Dugum.o ./lib/DogruKuyrugu.o ./lib/Nokta.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program