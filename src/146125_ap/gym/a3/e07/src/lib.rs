/*
Create a module called Point that inside has a struct `Point` with the fields `x: f32`, `y: f32`.
Create the following methods
  - `new` that initializes the Point
  - `distance` that borrow a Point and returns the distance between the two points
Create then another module called line that has a struct `Line` with the fields `start: Point`, `end: Point`, `m: f32` and `q: f32`
  - you have to implement the `new` method that takes two points and calculates the slope and the intercept of the line `m` and `q`
  - `contains` that borrow a `p: Point` and returns a `Result<_, String>`.
    The function should check if the `Line` contains the borrowed point
Create a third module called test that has a function `test` that creates a line and a point and tests the `contains` method.
*/

mod line;
mod point;
