#!/bin/bash -e

projectPath=$(dirname $(realpath $0))
buildPath=./build
#compile use cmake
buildAll () {
	cd $projectPath && git submodule update --init && cd -
	mkdir -p $buildPath && cd $buildPath && cmake $projectPath && make -j$(nproc)&& cd -
}

runAll () {
	buildAll && find $buildPath -maxdepth 1 -type f -executable -exec {} \;
	#buildAll && find build -maxdepth 1 -type f -executable -print|bash
}
formatSrc () {
	find $projectPath/src -regex '.*\.\(c\|cc\|cpp\|h\|hpp\|cxx\)' -exec clang-format -i --style=Google {} \;
}

checkSrc () {
	find $projectPath/src -regex '.*\.\(c\|cc\|cpp\|h\|hpp\|cxx\)' -exec cpplint {} \;
}

case $1 in 
	build)
		buildAll
		;;
	run)
		runAll
		;;
	format)
	  formatSrc
		;;
	check)
		checkSrc
		;;
	*)
		echo "$0 {build|run|format|check}"
		;;
esac
