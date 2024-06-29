#!/bin/bash
set -e

source libs/env_deploy.sh
DEST=$DEPLOYMENT/public_res
rm -rf $DEST
mkdir -p $DEST

#### Download geodata ####
curl -fLso $DEST/geoip.db "https://github.com/SagerNet/sing-geoip/releases/latest/download/geoip.db"
curl -fLso $DEST/geosite.db "https://github.com/SagerNet/sing-geosite/releases/latest/download/geosite.db"

#### copy res/public ####
cp res/public/* $DEST
