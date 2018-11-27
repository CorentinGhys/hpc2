 { pkgs ? import <nixpkgs> {} }:

with pkgs;

let

  # si besoin d'options particulières
  _opencv3 = opencv3.override {
    enableTIFF = false;
    enableWebP = false;
    enableEXR = false;
    enableJPEG2K = false;
    enableContrib = false;
    enableGtk3 = true;
    enableFfmpeg = true;
  };

in

stdenv.mkDerivation {

  name = "hpcOpencvCpp";

  src = ./.;

  buildInputs = [
    pkgconfig
    #_opencv3
    opencv3
  ];

  enableParallelBuilding = true;

  installPhase = ''
    mkdir -p $out/bin
    mv *.out $out/bin
  '';

}
