#!/bin/bash
ifconfig -a | grep :..: | sed 's/ether//g' | tr -d ' ' | tr -d '\t'
