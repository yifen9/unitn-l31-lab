/*
In Trento there is an automated car park with a camera that recognises the number plate of the car.
Your task is to associate the number plate with the owner of the car in order to track the price for each car owner.
Create a main with an appropriate data structure already initialised with some data.
Create a function `recognise_owner` that,
given the data structures mentioned above and the number of car plate,
returns an `Optional` value of the owner of the car
*/

#![allow(unused)]
fn main() {}

use std::collections::HashMap;

#[test]
fn test() {
    let mut hash_map: HashMap<String, String> = HashMap::new();
    hash_map.insert("CX196SP".to_string(), "James".to_string());
    hash_map.insert("SASSARI".to_string(), "Silvio".to_string());

    let mut parking = Parking::new(hash_map, 3);
    assert_eq!(
        parking.park_car("ZZ121PS".to_string(), "Mario".to_string(), 10.),
        Ok(10. * 0.25)
    );

    assert_eq!(
        parking.park_car("RT534LL".to_string(), "Luca".to_string(), 10.),
        Err("No more spots available")
    );

    assert_eq!(
        parking.exit_parking("NO".to_string()),
        Err("Car
not found")
    );
    assert_eq!(parking.exit_parking("ZZ121PS".to_string()), Ok(()))
}

struct Parking {
    parked_cars: HashMap<String, String>,
    remaining_spots: u32,
}

impl Parking {
    pub fn new(parked_cars: HashMap<String, String>, max_capacity: u32) -> Self {
        let remaining_spots = max_capacity - parked_cars.len() as u32;
        Self {
            parked_cars,
            remaining_spots,
        }
    }

    pub fn park_car(
        &mut self,
        car_plate: String,
        owner: String,
        minutes: f32,
    ) -> Result<f32, &str> {
        if self.remaining_spots > 0 {
            self.parked_cars.insert(car_plate, owner);
            self.remaining_spots -= 1;
            Ok(minutes * 0.25)
        } else {
            Err("No more spots available")
        }
    }

    pub fn exit_parking(&mut self, car_plate: String) -> Result<(), &str> {
        if let Some(_) = self.parked_cars.remove(&car_plate) {
            self.remaining_spots += 1;
            Ok(())
        } else {
            Err("Car not found")
        }

        // match self.parked_cars.remove(&car_plate) {
        //     Some(_) => {
        //         self.remaining_spots += 1;
        //         Ok(())
        //     }
        //     None => Err("Car not found"),
        // }
    }

    pub fn recognise_owner(s: String, hash: &mut HashMap<String, String>) -> Option<&String> {
        hash.get(&s)
    }
}
