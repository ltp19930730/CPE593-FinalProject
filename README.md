# High Performance Mandelbrot Set
#Team members:

Tianpei Luo;Dillon Guarino;Matthew Melachrinos

#What is a Mandelbrot set?

A mandelbrot set is a set of complex numbers that when graphed, form self similar patterns called fractals. Technically speaking, the mandelbrot set is “the set for which fc(z) = z2+ cdoes not diverge when iterated from z=0. When iterating the function, one of two things can happen. Either z grows to infinity, it “blows up” so to speak, or it stays bounded within r = 2. The mandelbrot set is the set of all numbers that stay bounded. 

There are numerous ways of graphing a mandelbrot set. One rudimentary way is to take a linear mapping approach. There are also distance estimator algorithms and histogram color table plots. However, more research needs to be done to find a simple, easy to implement visualization technique.

#Our Goals

Our goal, simply put, is to create efficient algorithms for generating mandelbrot sets to a large degree of detail in a fast way for the high iterations. This is a great project for an algorithms class because a brute force approach to this problem would be terribly slow. This leaves a large opportunity to develop better algorithms. 

#Our Approach 

First, we will develop a brute force algorithm. This serves two purposes. First, it helps us learn more about Mandelbrot sets. It also gives us a baseline to measure our later algorithms against. It’s commonly said that you can’t know happiness without knowing sadness. Similarly, you can’t know a good algorithm unless you know a bad one.

Second, we’ll build Mandelbrot sets using parallel calculations. Generating the set is a great opportunity for parallelism because you can start iterating from many different starting points at the same time. 

Third, we’ll develop other algorithms based on the research done. The professor suggests a rectangular containment algorithm but there are plenty of different algorithms to choose from. The group will develop 2 of these.

Finally, pending time constraints, the group will work on visualizing these sets. A simple set of numbers is not particularly interesting, especially in comparison to the beauty found in a visualization of these sets. However, this is not core to the project since it is an exercise in c++ programming not algorithm development. Ideally, a module will be found online that can be imported into the project that will display the sets generated from the projects algorithms. 
References

https://en.wikipedia.org/wiki/Mandelbrot_set

http://mathworld.wolfram.com/MandelbrotSet.html

https://www.youtube.com/watch?v=NGMRB4O922I

http://www.fractalforums.com/programming/newbie-how-to-map-colors-in-the-mandelbrot-set/

http://jonisalonen.com/2013/lets-draw-the-mandelbrot-set/

