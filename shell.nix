{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {

  name = "C++";

  buildInputs = with pkgs; [
    # builder
    gnumake
    cmake
    bear

    # debugger
    rocmPackages.llvm.lldb
    gdb

    # fix headers not found
    clang-tools

    # LSP and compiler
    pkgs.rocmPackages.llvm.libcxx

    # other tools
    cppcheck
    valgrind

    # libs
    glm
  ];

  shellHook = ''
    echo -e "C++ Shell Entered"
  '';

  stdenv = pkgs.clangStenv;
}
