#![allow(unused)]

use super::point::Point;

pub struct Line {
    start: Point,
    end: Point,
    m: f32,
    q: f32,
}

impl Line {
    pub fn new(start: Point, end: Point) -> Self {
        let m = (end.y - start.y) / (end.x - start.x);
        let q = end.y - start.y - m * (end.x - start.x);
        Line { start, end, m, q }
    }
    pub fn contains(&self, point: &Point) -> Result<(), &str> {
        let res = self.m * point.x + self.q;
        if point.y == res {
            Ok(())
        } else {
            Err("Not contained")
        }
    }
}
