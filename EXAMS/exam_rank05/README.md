# Exam Details

3 Questions in C++

*(!)This project has yet not been tested to check if it would pass the exam(!)*

:one: Warlock - [Subject Text](https://github.com/myagjz/42-Exam_Rank_05/blob/main/cpp_module00/subject.en.txt)

:two: Question 1 and Aspell, Atarget, Dummy and Fwoosh - [Subject Text](https://github.com/myagjz/42-Exam_Rank_05/blob/main/cpp_module01/subject.en.txt)

:three: Question 1, Question 2 and BrickWall, Fireball, Polymorph, SpellBook and TargetGenerator - [Subject Text](https://github.com/myagjz/42-Exam_Rank_05/blob/main/cpp_module02/subject.en.txt)

### Tips for exam

- All classes have to be canonical, but the exam's tester does only check for this matter on your *.hpp files*.. So, if you don't need to use some of the canonical parts **do not waste time implementing them in the .cpp files** (for instance: overload, copy constructor...)

- Use `#pragma once` on first line of your .hpp file, this replaces `#ifndef `- `#define `- `#endif`, which will save you lines and time

- There are so many files to create on this exam, so in order to save time and avoid typos, it would be wise to **copy/paste them from the subject and use the `touch` command on terminal**

- You will realize that several files are quite similar, so you can use the command `cat FileOne.cpp > FileTwo.cpp` (being FileTwo.cpp empty before using the command, obviously), then search/replace a few words and that's it, you are done with it

- Having in mind the two previous ideas, your workflow between modules could be: copy needed files from previous module (modify them later if needed by subject) - created new required files with `touch` - use `cat FileOne > FileTwo` for similar files - search/replace in new files to modify them as needed - create rest of needed files from scratch

- Be careful with logs or outputs messages, the exam tester can fail your submission if you miss a final dot on a sentence, so better keep the subject aside and **copy/paste all required output messages!**

### Pre-configure Vim for a better exam experience

The exam session will have vim cofigured as less user friendly as possible. You can activate some features in each editor if you want, but each time you open a new one, those will be lost. In order to make this features persistent, we can modify `~/.vimrc`, which is the configuration file for vim. This file may not even exist on the exam session, don't worry, we can create it.

```bash
	vim ~/.vimrc
```

```bash
	# On vimrc file, add these lines:
	set number
	set mouse=a
	syntax enable
```

- **Copy/paste in Vim** -> in visual mode -> *Y*(copY) - *P*(Paste); this will paste after cursor

- **Allow copy/paste with cursor** -> in visual mode -> just try to select with cursor and then use right-mouse-button or `CTRL+C`, `CTRL+V` for copy and paste; if not working	you need to enable in vim configuration as explained before.

- **Search/replace in Vim** -> `:%s/old/new/g` -> will replace any occurency of *"old"* for *"new"* in the whole file (because of `g` flag, without it, it would replace only first occurency)
> Tip: in visual mode, you can use `*` to store the word on cursor, then you can just do `:%s//new/g` and the first param of the command will be replaced by the word 'stored' by `*` (or /search)

- **Safer search/replace in Vim** -> `:%s/\<old\>/new/gc` -> using word boundries (`\<` and `\>`) will replace only whole exactly words occurencies, e.g. *old* → new (replaced); *old*er → older (unchanged)...; also the `c` flag will add confirmation for each replacement

- **Undo/redo in Vim** -> `u` undo last change; `CTRL+R` redo last undone change

### Total Excepted Files

> 16 .cpp (c++ files) and 16 .hpp (header files) = 32 files total.
