#!/bin/bash
cp ../reactos/sdk/lib/atl/*.h include/atl
cp -r ../reactos/modules/rostests/apitests/atl/*.bmp atltests
cp -r ../reactos/modules/rostests/apitests/atl/*.cpp atltests
cp -r ../reactos/modules/rostests/apitests/atl/*.inl atltests
cp -r ../reactos/modules/rostests/apitests/atl/*.h atltests
cp -r ../reactos/modules/rostests/apitests/atl/*.rc atltests
cp -r ../reactos/modules/rostests/apitests/atl/devenv/*.sln atltests/devenv
cp -r ../reactos/modules/rostests/apitests/atl/devenv/*.vcxproj atltests/devenv
git apply RATL.diff
