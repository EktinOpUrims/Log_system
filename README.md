# Log_system

1) To run the program execute the following in the terminal:

```g++ .\Main.cpp .\log\log.cpp .\get_time\get_time.cpp .\generate_color\generate_color.cpp .\globals\globals.cpp -Ilog -I get_time -Igenerate_color -Iglobals```

2) To see an example of output, go to ```log_outputs\log.txt```, ```log_outputs\log2.txt```

3) If your terminal supports coloured output, set ```bool colored_output_mode = 1;``` in ```globals\globals.cpp```