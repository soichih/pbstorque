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
const torque = require('../build/Release/addon');
console.log(torque.statque());

```

```
{ trinity: 
   { queue_type: 'Execution',
     max_queuable: 500,
     total_jobs: 3,
     state_count: 
      { Transit: 0,
        Queued: 1,
        Held: 0,
        Waiting: 0,
        Running: 2,
        Exiting: 0,
        Complete: 0 },
     acl_hosts: 
      [ 't3.karst.uits.iu.edu',
        't2.karst.uits.iu.edu',
        't1.karst.uits.iu.edu' ],
     acl_user_enable: true,
     acl_users: 'befulton,cganote,cgayde,hbrokaw,henschel,hpc,huili,jgronek,jrinkovs,lewu,malallen,trinity,wagnermi',
     from_route_only: false,
     resources_max: '336:00:00',
     mtime: Fri Oct 14 2016 09:41:39 GMT-0400 (EDT),
     resources_assigned: '601295421440b',
     enabled: true,
     started: true },
  batch: 
   { queue_type: 'Route',
     total_jobs: 0,
     state_count: 
      { Transit: 0,
        Queued: 0,
        Held: 0,
        Waiting: 0,
        Running: 0,
        Exiting: 0,
        Complete: 0 },
     resources_default: '00:30:00',
     mtime: Tue Aug 02 2016 10:36:53 GMT-0400 (EDT),
     route_destinations: 'serial,normal,long',
     enabled: true,
     started: true },
  interactive: 
   { queue_type: 'Execution',
     max_queuable: 128,
     max_user_queuable: 16,
     total_jobs: 2,
     state_count: 
      { Transit: 0,
        Queued: 0,
        Held: 0,
        Waiting: 0,
        Running: 2,
        Exiting: 0,
        Complete: 0 },
     acl_hosts: 
      [ 'c8.karst.uits.iu.edu',
        'c7.karst.uits.iu.edu',
        'c6.karst.uits.iu.edu',
        'c5.karst.uits.iu.edu' ],
     acl_user_enable: true,
     acl_users: '+',
     from_route_only: false,
     resources_max: '08:00:00',
     mtime: Tue Aug 02 2016 10:36:53 GMT-0400 (EDT),
     disallowed_types: 'batch',
     resources_assigned: '0b',
     max_user_run: '2',
     enabled: true,
     started: true },
  debug: 
   { queue_type: 'Execution',
     max_user_queuable: 2,
     total_jobs: 2,
     state_count: 
      { Transit: 0,
        Queued: 2,
        Held: 0,
        Waiting: 0,
        Running: 0,
        Exiting: 0,
        Complete: 0 },
     acl_hosts: 
      [ 'c4.karst.uits.iu.edu',
        'c3.karst.uits.iu.edu',
        'c2.karst.uits.iu.edu',
        'c1.karst.uits.iu.edu' ],
     acl_user_enable: true,
     acl_users: '+',
     from_route_only: false,
     resources_max: '01:00:00',
     mtime: Tue Aug 02 2016 10:36:53 GMT-0400 (EDT),
     resources_assigned: '0b',
     enabled: true,
     started: true },
  condo: 
   { queue_type: 'Execution',
     max_queuable: 1800,
     max_user_queuable: 448,
     total_jobs: 8,
     state_count: 
      { Transit: 0,
        Queued: 4,
        Held: 0,
        Waiting: 0,
        Running: 4,
        Exiting: 0,
        Complete: 0 },
     acl_hosts: 
      [ 'c249.karst.uits.iu.edu',
        '...',
        'c230.karst.uits.iu.edu' ],
     acl_user_enable: true,
     acl_users: 'abhsingh,agopu,ajwomack,anabiman,anaemami,artvaldi,bradluen,browstev,bsmusick,chlucero,cjcrowle,cyiannou,dajmcdon,dalittle,davmontg,dbking,dmanriqu,glpuetz,hbolte,hjoshi,huang48,huili,jgronek,jgrosch,jj228,jjisrael,johespin,jrinkovs,jslong,jw257,kailiu,kchow,khanna,kkhadke,ldriggen,mfrisby,mgerpe,mkudela,mtrosset,nlcurtis,odidev,oditest,odiuser,pwstaten,raquick,rconrick,sd3,somogyie,srevale,ssshinde,stanwass,tovara,weihuaan,xuecliu,yangjing,youngmd,ysereda,zgrey,zpreynol',
     from_route_only: false,
     resources_max: '336:00:00',
     acl_group_enable: 'True',
     acl_groups: 'ccvt,dal,iedea,odi,pwstatengrp,stats',
     mtime: Tue Sep 06 2016 13:06:03 GMT-0400 (EDT),
     resources_assigned: '4',
     enabled: true,
     started: true },
  long: 
   { queue_type: 'Execution',
     max_queuable: 2000,
     total_jobs: 773,
     state_count: 
      { Transit: 0,
        Queued: 727,
        Held: 0,
        Waiting: 0,
        Running: 46,
        Exiting: 0,
        Complete: 0 },
     acl_hosts: 
      [ 'c199.karst.uits.iu.edu',
        '...',
        'c100.karst.uits.iu.edu' ],
     acl_user_enable: true,
     acl_users: '+',
     from_route_only: true,
     resources_max: '336:00:00',
     mtime: Tue Aug 02 2016 10:36:53 GMT-0400 (EDT),
     resources_assigned: '0b',
     enabled: true,
     started: true },
  normal: 
   { queue_type: 'Execution',
     max_queuable: 2000,
     total_jobs: 942,
     state_count: 
      { Transit: 0,
        Queued: 755,
        Held: 27,
        Waiting: 0,
        Running: 160,
        Exiting: 0,
        Complete: 0 },
     acl_hosts: 
      [ 'c199.karst.uits.iu.edu',
        '...',
        'c100.karst.uits.iu.edu' ],
     acl_user_enable: true,
     acl_users: '+',
     from_route_only: true,
     resources_max: '168:00:00',
     mtime: Tue Aug 02 2016 10:36:53 GMT-0400 (EDT),
     resources_assigned: '161061273600b',
     enabled: true,
     started: true },
  serial: 
   { queue_type: 'Execution',
     max_queuable: 2000,
     total_jobs: 87,
     state_count: 
      { Transit: 0,
        Queued: 63,
        Held: 0,
        Waiting: 0,
        Running: 23,
        Exiting: 0,
        Complete: 1 },
     acl_hosts: 
      [ 'c199.karst.uits.iu.edu',
        '...',
        'c100.karst.uits.iu.edu' ],
     acl_user_enable: true,
     acl_users: '+',
     from_route_only: true,
     resources_max: '12:00:00',
     mtime: Thu Oct 20 2016 11:32:20 GMT-0400 (EDT),
     resources_assigned: '4294967296b',
     enabled: true,
     started: true },
  preempt: 
   { queue_type: 'Execution',
     max_queuable: 1800,
     max_user_queuable: 200,
     total_jobs: 120,
     state_count: 
      { Transit: 0,
        Queued: 96,
        Held: 0,
        Waiting: 0,
        Running: 24,
        Exiting: 0,
        Complete: 0 },
     acl_hosts: 
      [ 'c249.karst.uits.iu.edu',
        '...',
        'c230.karst.uits.iu.edu' ],
     acl_user_enable: true,
     acl_users: '+',
     from_route_only: false,
     resources_max: '336:00:00',
     mtime: Tue Aug 02 2016 10:36:53 GMT-0400 (EDT),
     resources_assigned: '0b',
     enabled: true,
     started: true } }

```
