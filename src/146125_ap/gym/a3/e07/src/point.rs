#![allow(unused)]

pub struct Point {
    pub x: f32,
    pub y: f32,
}

impl Point {
    pub fn new(x: f32, y: f32) -> Self {
        Point { x, y }
    }

    pub fn distance(&self, other: &Point) -> f32 {
        let x = (self.x - other.x).powi(2);
        let y = (self.y - other.y).powi(2);
        (x + y).sqrt()
    }
}
