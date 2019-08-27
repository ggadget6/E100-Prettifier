# E100-Prettifier

The E100 Prettifier "prettifies" programs written in the E100 programming language, according to the style guide provided [here](https://www-personal.umich.edu/~rovinski/e100/codestyle.html). Specifically, this prettifier: 
1. Converts tabs into spaces. 
2. Lines up columns by varying the number of spaces between columns. The number of spaces changes to ensure that the distance between the longest word in a column and the next column is four spaces. 
3. Ignores lines beginning with comments so that spacing isn't messed up. Lines which end with comments are adjusted so that the comments line up at their beginning. 

## Installation

Clone the project using git

```bash
git clone https://github.com/ggadget6/E100-Prettifier.git
```

## Usage

```bash
make pretty infilename=(input here) outfilename=(output here)
```

Replace "input here" with the name of your input file and "output here" with the name of your output file. I recommend that you don't make the output filename the same as the input filename just in case the output doesn't come out like you want it to. Don't include the parentheses when typing your file names.

### Example

```bash
make pretty infilename=sd_driver.e outfilename=sd_driver_pretty.e
```

It's also important to make sure that the file you want to make pretty is either in the same directory as the E100-Prettifier project, or that you give the program the full file path when running it.

### Example
```bash
make pretty infilename=/home/username/Documents/sd_driver.e outfilename=/home/username/Documents/sd_driver_pretty.e
```
