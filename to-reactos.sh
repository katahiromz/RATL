#!/bin/bash
cp -r atl/*.h ../reactos/sdk/lib/atl
cp -r atltests/*.bmp ../reactos/modules/rostests/apitests/atl
cp -r atltests/*.cpp ../reactos/modules/rostests/apitests/atl
cp -r atltests/*.inl ../reactos/modules/rostests/apitests/atl
cp -r atltests/*.h ../reactos/modules/rostests/apitests/atl
cp -r atltests/devenv/*.sln ../reactos/modules/rostests/apitests/atl/devenv
cp -r atltests/devenv/*.vcxproj ../reactos/modules/rostests/apitests/atl/devenv
