#!/bin/bash
$SCRIPT_BEGIN

### DGtal build
cd "$BUILD_DIR"
make -j $BJOBS DGtal

$SCRIPT_END
