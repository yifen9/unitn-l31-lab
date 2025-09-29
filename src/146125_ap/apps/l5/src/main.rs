struct User {
    pub(crate) username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}

fn main() {
    println!("Hello, world!");

    let _user0 = User {
        email: String::from("someone@example.com"),
        username: String::from("someusername123"),
        active: true,
        sign_in_count: 1,
    }; // Q: can i uncomment the line below ?
    // _user0.email = String::new();
    let mut user1 = User {
        email: String::from("someone@example.com"),
        username: String::from("someusername123"),
        active: true,
        sign_in_count: 1,
    };
    user1.email = String::new();
    user1.username = String::new();

    // QUIZ: if i go into a different file `c04_structshelper`,
    // can i write
    // let x = user1.email;

    let email = String::from("someone@example.com");
    let username = String::from("someusername123");

    let _user2 = User {
        email,
        username,
        active: true,
        sign_in_count: 1,
    };

    let user3 = User {
        email: String::from("someone@example.com"),
        username: String::from("someusername123"),
        active: true,
        sign_in_count: 1,
    };

    let _user4 = User {
        email: String::from("another@example.com"),
        username: String::from("anotherusername567"),
        ..user3
    };
    let _user5 = User {
        email: String::from("another@example.com"),
        username: String::from("anotherusername567"),
        active: user1.active,
        sign_in_count: user1.sign_in_count,
    };
}
