{ pkgs }: {
    deps = [
      pkgs.vim
      pkgs.openssh
      pkgs.pandoc
      pkgs.glibcLocales
      pkgs.gitFull
      pkgs.libev
      pkgs.gnuplot
      pkgs.ncurses.dev
      pkgs.gd
    ];
}
