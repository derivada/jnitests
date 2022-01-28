## JNI Tests

#### JNI (Java Native Interface) can be using for running C/C++ from Java (or viceversa).

Using: Ubuntu 20.04.3 LTS x86_64 on VirtualBox VM, with gcc version 9.3.0 and openjdk version "11.0.13" 2021-10-19
OpenJDK Runtime Environment (build 11.0.13+8-Ubuntu-0ubuntu1.20.04)

This is the tutorial that I used to get this working:
https://www3.ntu.edu.sg/home/ehchua/programming/java/JavaNativeInterface.html

Some other resources for compiling and libraries:
* https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html
* https://stackoverflow.com/questions/973146/how-to-include-header-files-in-gcc-search-path
* https://stackoverflow.com/questions/6804253/jni-h-no-such-file-or-directory
* VSCode IntelliSense setup for "jni.h": https://stackoverflow.com/questions/46258143/visual-studio-code-how-to-configure-includepath-for-better-intellisense-results

And this is the final list of commands that I used for running the example:

1. `javac -h . Example1.java` for compiling the Java class into bytecode and creating the `.h` header at the same time. Note that before Java 8, the command `javah` was used, but it's now obsolete.
2. `gcc -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -shared -o libexample1.so example1.c` for compiling the C program as a shared library. The arguments `-I` help gcc find the path to the `jni.h` and `jni_md.h` headers.
3. `java -Djava.library.path=. Example1` for running the Java program. It needs a place to find the `.so` library, in this case that is the current directory and we provide that with the first argument.

The `JAVA_HOME` environment variable must have been first set using:

* `export JAVA_HOME=/usr/lib/jvm/java-1.11.0-openjdk-amd64` or whatever path there is to your JDK installation
* `echo $JAVA_HOME` to test it has been set correctly

#### TODO: Test the running time of simple programs to see if this really helps with speed