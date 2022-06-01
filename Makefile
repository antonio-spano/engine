O := obj/
ALL = $Omain.o $Ofile.o $Oshader.o $Osprite.o $Oinput.o $Omath.o $Ophysics.o $Ogameobject.o $OComponent.o $Ostb_image.o UpdateList.hpp scripts.hpp SpriteList.hpp
SCRIPTS = Test.hpp Test2.hpp

out: $(ALL) $(SCRIPTS)
	@g++ -o out $O*.o glad.c -lglfw
	@echo "done!";

$Omain.o: main.cpp
	@g++ -c main.cpp -o $Omain.o

$Ofile.o: file.*
	@g++ -c file.cpp -o $Ofile.o

$Oshader.o: shader.*
	@g++ -c shader.cpp -o $Oshader.o

$Osprite.o: sprite.*
	@g++ -c sprite.cpp -o $Osprite.o

$Oinput.o: input.*
	@g++ -c input.cpp -o $Oinput.o

$Omath.o: math.*
	@g++ -c math.cpp -o $Omath.o

$Ophysics.o: physics.*
	@g++ -c physics.cpp -o $Ophysics.o

$Ogameobject.o: gameobject.*
	@g++ -c gameobject.cpp -o $Ogameobject.o

$OComponent.o: Component.*
	@g++ -c Component.cpp -o $OComponent.o

$Ostb_image.o: stb_image.cpp
	@g++ -c stb_image.cpp -o $Ostb_image.o

run:
	./out

clean:
	rm obj/*.o out
