#!/bin/sh

#
# pdm_generate.sh
#
# Copyright (C) 2019, Cirrent Inc
#
# All use of this software must be covered by a license agreement as described in
# Cirrent Terms of Services (https://www.cirrent.com/terms-of-service/)
#
# DISCLAIMER. THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OR CONDITION,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. LICENSORS HEREBY DISCLAIM
# ALL LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE.
#

# This is the script which generates a PDM data source file for specific device credentials
#

if [ "$#" -ne 3 ] && ( [ "$#" -ne 4 ] || [ "$4" != "-t" ] ); then
    cat <<EOF >&2
Script generates initial zipkey configuration in PDM format
Usage: $0 <ACC ID> <DEVICE ID> <SECRET> [-t]
Options:
  -t = the credentials are temporary
EOF
    read -p "Press enter to continue"
    exit 1
fi

CLOUD_URL_BASE=https://dev.cirrentsystems.com/2016-01/config/0
ZIPKEY_CONF="zipkey_conf.bin"

ACC_ID=$1
DEV_ID=$2
SECRET=$3

if [ -n "$4" ]; then
    IS_TEMPORARY=1
else
    IS_TEMPORARY=0
fi

secret_length=${#SECRET}
API_KEY="$(expr substr $SECRET $((secret_length / 4 + 1))  $((secret_length - 2 * (secret_length / 4))))"

rm -f $ZIPKEY_CONF
echo "Downloading zipkey_conf.bin"
echo "Username = ${ACC_ID}_${DEV_ID}"
echo "API Key = ${API_KEY}"
curl -f -s -H 'x-response-type: binary' --user ${ACC_ID}_${DEV_ID}:${API_KEY} -X GET ${CLOUD_URL_BASE} -o $ZIPKEY_CONF
if [ $? -ne 0 ]; then
    echo "Error downloading zipkey_conf.bin"
    read -p "Press enter to continue"
    exit 1
fi
ls -l $ZIPKEY_CONF

echo "Generating PDM binary file"
./pdm_data_create -c cirrent_certs.pem -z $ZIPKEY_CONF $ACC_ID $DEV_ID $SECRET
if [ $? -ne 0 ]; then
    echo "Error generating PDM data file."
    read -p "Press enter to continue"
    exit 1
else
    echo "ca_config_data.h file generated !"
    read -p "Press enter to continue"
fi
