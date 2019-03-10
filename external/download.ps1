# Include functions.
. .\functions.ps1

$packages = @(@{ name = "arithmetic-functors"; version = "2.3" },
              @{ name = "byte-orders"; version = "1.5"},
              @{ name = "errors"; version = "1.5" },
              @{ name = "functors"; version = "1.3"},
              @{ name = "math-colors"; version = "0.2" },
              @{ name = "math-matrices"; version = "1.3" },
              @{ name = "math-non-scalars"; version = "1.3" },
              @{ name = "math-points"; version = "0.3" },
              @{ name = "math-scalars"; version = "1.4" },
              @{ name = "math-trigonometry"; version = "1.4" },
              @{ name = "math-vectors"; version = "1.0" },
              @{ name = "one-zero-functors"; version = "1.6" },
              @{ name = "relational-functors"; version = "1.8" },
              @{ name = "trigonometric-functors"; version = "1.0" } );

foreach($package in $packages) {
  Download -PackageName $package['name'] -Version $package['version']
}
