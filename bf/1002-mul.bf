,                           # Read first digit (in ASCII)
-48                         # Convert from ASCII to actual number
>                           # Move to next cell
,                           # Read second digit (in ASCII)
-48                         # Convert from ASCII to actual number
[                           # Start loop (runs for the number of times equal to the second digit)
  <+                        # Move to first cell and increment
  >-                        # Move to second cell and decrement
]                           # End loop
<                           # Move back to first cell
.                           # Print result
