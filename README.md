# crystal-autogui

GUI Automation Library for Crystal

## Installation

1. Add the dependency to your `shard.yml`:

   ```yaml
   dependencies:
     crystal-autogui:
       github: hrichharms/crystal-autogui
   ```

2. Run `shards install`

## Building C Object Files
screen.c -> screen.o

`gcc -c screen.c -o screen.o -lX11`


mouse.c -> mouse.o

`gcc -c mouse.c -o mouse.o -lX11 -lXtst`


keyboard.c -> keyboard.o

`gcc -c keyboard.c -o keyboard.o -lX11 -lXtst`


## TODO List
- Automatic string writing
- Character to Key-code mapping for easier keyboard function use
- Mouse scrolling

## Contributing

1. Fork it (<https://github.com/your-github-user/crystal-autogui/fork>)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request
