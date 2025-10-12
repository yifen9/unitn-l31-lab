```
cargo check

cargo new apps/test
cargo run -p test

cargo test
cargo test -p test

cargo fmt
cargo clippy

cargo doc --open

cargo new libs/helpers

apps/test/Cargo.toml

[dependencies]
helpers = { path = "../../libs/helpers" }
```