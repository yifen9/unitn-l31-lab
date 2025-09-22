```
cargo check --workspace

cargo new apps/test --bin
cargo run -p test

cargo test --workspace
cargo test -p test

cargo fmt --all
cargo clippy --all-targets --all-features

cargo new libs/helpers --bin

apps/test/Cargo.toml

[dependencies]
helpers = { path = "../../libs/helpers" }
```