# 3D-reconstruction-oldschool

This is a project i made last year for the class Mathematical Modeling: from 2 pictures of a calibration pattern (which i uploaded here), using the same camera (slightly moving the camera on a single axis), can get relevant information on position and depth.
Then modeling the problem can abstract the problem to the resolution of equation systems using matrices, which is done by this program using the C++ library Octave.
Then one can just select a set of points on a image (taken by the same camera, in the same positions, just placing an object to reconstruct) and plot them to have a reconstruction of the 3D object as a graph.
It's a very simplistic way, and not really efficient as methods and libraries exist now to do the same and not just extract points, but also extract 3D meshes, but it's a good practice on how this works from the "bones", also a good practice on Octave and matrix manipulation
