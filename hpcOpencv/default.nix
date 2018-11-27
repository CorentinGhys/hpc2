# { pkgs ? (import <nixpkgs> { config = import ./config.nix; }) }:
{ pkgs ? (import <nixpkgs> {}) }:

with pkgs;

let 

  _pyPkgs = python3Packages;

  _pyopencv3 = _pyPkgs.opencv3.override {

    enableTIFF = false;
    enableWebP = false;
    enableEXR = false;
    enableJPEG2K = false;
    enableContrib = false;

    enableGtk3 = true;
    enableFfmpeg = true;
    # enableCuda = true;
  };


in 

_pyPkgs.buildPythonPackage {
  name = "hpcOpencv";
  src = ./.;
  buildInputs = [ 
    _pyPkgs.matplotlib
    _pyPkgs.numpy
    _pyPkgs.tkinter
    _pyopencv3
  ];
}
