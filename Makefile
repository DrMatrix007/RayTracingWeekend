

run_to_file:
	mkdir -p build;
	cd build; cmake build .
	cd build; make
	rm file.ppm
	build/RTWeekend >> "file.ppm"
	gimp file.ppm