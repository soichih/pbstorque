# PBS Torque

nodejs native binding for PBS Torque from adaptivecomputing

Disclaimer: I have no association to adaptivecomputing. I am mainly developing this for my own purpose, but please feel free to use this if you want to interface with your PBS cluster.

> For PBS torque, please see https://github.com/adaptivecomputing/torque/

## Dependencies

* libtorque
* libtorque header files in /usr/local/include
* boost (for hpc, try module load boost)

## Build

npm build

## Test

npm test

## Usage

### Queue Status

Get current queue status.

For now this is the only method that this module supports..Yes, that's very sad.. but this is a start!

```
const torque = require('pbstorque');
console.log(torque.statque());

```

```json
{
    "trinity": {
        "queue_type": "Execution",
        "max_queuable": 500,
        "total_jobs": 3,
        "state_count": {
            "Transit": 0,
            "Queued": 1,
            "Held": 0,
            "Waiting": 0,
            "Running": 2,
            "Exiting": 0,
            "Complete": 0
        },
        "acl_hosts": [
            "t3.karst.uits.iu.edu",
            "t2.karst.uits.iu.edu",
            "t1.karst.uits.iu.edu"
        ],
        "acl_user_enable": true,
        "acl_users": [
            "befulton",
            "cganote",
            "cgayde",
            "hbrokaw",
            "henschel",
            "hpc",
            "huili",
            "jgronek",
            "jrinkovs",
            "lewu",
            "malallen",
            "trinity",
            "wagnermi"
        ],
        "from_route_only": false,
        "resources_max": "336:00:00",
        "mtime": "2016-10-14T13:41:39.000Z",
        "resources_assigned": "601295421440b",
        "enabled": true,
        "started": true
    },
    "batch": {
        "queue_type": "Route",
        "total_jobs": 0,
        "state_count": {
            "Transit": 0,
            "Queued": 0,
            "Held": 0,
            "Waiting": 0,
            "Running": 0,
            "Exiting": 0,
            "Complete": 0
        },
        "resources_default": "00:30:00",
        "mtime": "2016-08-02T14:36:53.000Z",
        "route_destinations": [
            "serial",
            "normal",
            "long"
        ],
        "enabled": true,
        "started": true
    },
    "interactive": {
        "queue_type": "Execution",
        "max_queuable": 128,
        "max_user_queuable": 16,
        "total_jobs": 2,
        "state_count": {
            "Transit": 0,
            "Queued": 0,
            "Held": 0,
            "Waiting": 0,
            "Running": 2,
            "Exiting": 0,
            "Complete": 0
        },
        "acl_hosts": [
            "c8.karst.uits.iu.edu",
            "c7.karst.uits.iu.edu",
            "c6.karst.uits.iu.edu",
            "c5.karst.uits.iu.edu"
        ],
        "acl_user_enable": true,
        "acl_users": [
            "+"
        ],
        "from_route_only": false,
        "resources_max": "08:00:00",
        "mtime": "2016-08-02T14:36:53.000Z",
        "disallowed_types": "batch",
        "resources_assigned": "0b",
        "max_user_run": "2",
        "enabled": true,
        "started": true
    },
    "debug": {
        "queue_type": "Execution",
        "max_user_queuable": 2,
        "total_jobs": 2,
        "state_count": {
            "Transit": 0,
            "Queued": 2,
            "Held": 0,
            "Waiting": 0,
            "Running": 0,
            "Exiting": 0,
            "Complete": 0
        },
        "acl_hosts": [
            "c4.karst.uits.iu.edu",
            "c3.karst.uits.iu.edu",
            "c2.karst.uits.iu.edu",
            "c1.karst.uits.iu.edu"
        ],
        "acl_user_enable": true,
        "acl_users": [
            "+"
        ],
        "from_route_only": false,
        "resources_max": "01:00:00",
        "mtime": "2016-08-02T14:36:53.000Z",
        "resources_assigned": "0b",
        "enabled": true,
        "started": true
    },
    "condo": {
        "queue_type": "Execution",
        "max_queuable": 1800,
        "max_user_queuable": 448,
        "total_jobs": 8,
        "state_count": {
            "Transit": 0,
            "Queued": 4,
            "Held": 0,
            "Waiting": 0,
            "Running": 4,
            "Exiting": 0,
            "Complete": 0
        },
        "acl_hosts": [
            "c249.karst.uits.iu.edu",
            "c239.karst.uits.iu.edu",
            "c229.karst.uits.iu.edu",
            "c248.karst.uits.iu.edu",
            "c238.karst.uits.iu.edu",
            "c247.karst.uits.iu.edu",
            "c237.karst.uits.iu.edu",
            "c256.karst.uits.iu.edu",
            "c246.karst.uits.iu.edu",
            "c236.karst.uits.iu.edu",
            "c255.karst.uits.iu.edu",
            "c245.karst.uits.iu.edu",
            "c235.karst.uits.iu.edu",
            "c254.karst.uits.iu.edu",
            "c244.karst.uits.iu.edu",
            "c234.karst.uits.iu.edu",
            "c253.karst.uits.iu.edu",
            "c243.karst.uits.iu.edu",
            "c233.karst.uits.iu.edu",
            "c252.karst.uits.iu.edu",
            "c242.karst.uits.iu.edu",
            "c232.karst.uits.iu.edu",
            "c251.karst.uits.iu.edu",
            "c241.karst.uits.iu.edu",
            "c231.karst.uits.iu.edu",
            "c250.karst.uits.iu.edu",
            "c240.karst.uits.iu.edu",
            "c230.karst.uits.iu.edu"
        ],
        "acl_user_enable": true,
        "acl_users": [
            "abhsingh",
            "agopu",
            "ajwomack",
            "anabiman",
            "anaemami",
            "artvaldi",
            "bradluen",
            "browstev",
            "bsmusick",
            "chlucero",
            "cjcrowle",
            "cyiannou",
            "dajmcdon",
            "dalittle",
            "davmontg",
            "dbking",
            "dmanriqu",
            "glpuetz",
            "hbolte",
            "hjoshi",
            "huang48",
            "huili",
            "jgronek",
            "jgrosch",
            "jj228",
            "jjisrael",
            "johespin",
            "jrinkovs",
            "jslong",
            "jw257",
            "kailiu",
            "kchow",
            "khanna",
            "kkhadke",
            "ldriggen",
            "mfrisby",
            "mgerpe",
            "mkudela",
            "mtrosset",
            "nlcurtis",
            "odidev",
            "oditest",
            "odiuser",
            "pwstaten",
            "raquick",
            "rconrick",
            "sd3",
            "somogyie",
            "srevale",
            "ssshinde",
            "stanwass",
            "tovara",
            "weihuaan",
            "xuecliu",
            "yangjing",
            "youngmd",
            "ysereda",
            "zgrey",
            "zpreynol"
        ],
        "from_route_only": false,
        "resources_max": "336:00:00",
        "acl_group_enable": "True",
        "acl_groups": [
            "ccvt",
            "dal",
            "iedea",
            "odi",
            "pwstatengrp",
            "stats"
        ],
        "mtime": "2016-09-06T17:06:03.000Z",
        "resources_assigned": "4",
        "enabled": true,
        "started": true
    },

```
