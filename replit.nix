{ pkgs }: {
    deps = [
      pkgs.pandoc
      pkgs.glibcLocales
      pkgs.gitFull
      pkgs.libev
      pkgs.gnuplot
      pkgs.ncurses.dev
      pkgs.gd
    ];
}
