# 2nd LE Reviewer: Lists, Stacks, Queues, Deques

Source of `../Second Long Exam - Lists, Stacks, Queues, Deques.pdf`.

    code/        every program shown in the book
      lib/       the course structures (sll.h, dll.h, stackqueue.h, deque.h) + test harness
      listings/  Part I listings (arraylist.c, intvector.cpp, dllist.cpp, circular.c, ...)
      notes/     demo programs whose output is printed in the book (incl. P13/P14 templates)
      tracing/   Section B programs t01..t25
      sol/       Section C solutions p01..p57
      test/      self-checking tests (samples, brute force, heap-block counting)
      out/       captured program output, included verbatim in the PDF
    src/         LaTeX source (reviewer.tex is the main file)

## Build

1. Programs and tests (gcc/g++ in PATH, e.g. MSYS2 MinGW):

       bash code/build.sh            # everything
       bash code/build.sh t21        # only files whose name contains "t21"

   Each test prints `ok: N checks, 0 failures`.

2. PDF (XeLaTeX; tested with Tectonic 0.15):

       cd src && tectonic reviewer.tex

   Fonts: TeX Gyre Pagella, Inconsolata, TeX Gyre Pagella Math.

Run step 1 before step 2 whenever a program changes: the book includes `code/out/*.txt`.
