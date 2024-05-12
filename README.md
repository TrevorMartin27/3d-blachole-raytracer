# Blackhole Raytracer

In an attempt to understand [gravitational lensing](https://en.wikipedia.org/wiki/Gravitational_lens),
we (a group of foolish students) decided to write a raytracer that is able to
(somewhat) correctly simulate light according to Einstein's Theory of General
Relativity.

## Why Does This Matter?

This project is an interesting intersection between Physics and Computer Science.
Where Physics has much of the math necessary to correctly model complex phenomina,
Computer Science offers access to the computations necessary to demonstrate
this phenomina to lesser mortals without degrees in theoretical physics.

This problem (simulating light) is extremely difficult, because Newton's well-known
equation:

$F_G = G * \frac{m_1 * m_2}{r^2}$

Breaks down when dealing with large masses and high speeds; this is coincidentally
expactly the conditions we are attempting to model.

Instead, we need to follow Einstein's understand of gravity as mass warping
space itself, causing light to bend despite it (locally) remaining straight.
We want to simulate that.

That's what this project is.

While we aren't contributing anything novel to the fields of Physics, Mathematics,
or Computer Science---we hope to demonstrate the importance of collaboration and
the vitality of curiosity-driven learning.

## Building

The build process should be very similar between platforms.

### Requirements
 * CMake
 * C++ 17 Compliant Compiler

```sh
# NOTE: Not including optimization options for compiler
cmake -B build
cmake --build build
```

## TODO
- [ ] Finish README
- [ ] Physics Preparation
   - [ ] Extend polar coordinates from *Nattawat Radjaroendee et al* to cartesian coordinates
   - [ ] Using cartesian coordinates, support multiple black holes
   - [ ] Extend 2d cartesian coordinates into 3d cartesian coordinates
- [ ] Rendering Preparation
   - [ ] Image saving
   - [ ] Basic objects (sphere plane)
   - [ ] Basic materials (flat, diffuse, etc)
   - [ ] Basic lighting system (this will be fun)
   - [ ] Look into transitioning to raymarching
   - [ ] More complex objects (triangle, torus, fractals???)
- [ ] Scene loader
   - [ ] Animations
- [ ] Skybox (this would be really cool)

## Resources

[Nattawat Radjaroendee et al 2023 J. Phys.: Conf. Ser. 2653 012024](https://iopscience.iop.org/article/10.1088/1742-6596/2653/1/012024)
