{
  "targets": [
    {
      "target_name": "qstat",
      "sources": [ "qstat.cc" ],
      "include_dirs": [ "/usr/local/include" ],
      "libraries": [ '-ltorque' ]
    },
    {
      "target_name": "pbsnodes",
      "sources": [ "pbsnodes.cc" ],
      "include_dirs": [ "/usr/local/include" ],
      "libraries": [ '-ltorque' ]
    }
  ],
}
