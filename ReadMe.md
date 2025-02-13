# PUSHBUTTON_SWITCH_LIB - simple C cross-platform library 
![keypad_lib](https://github.com/user-attachments/assets/91f53293-e0e2-43eb-ac10-cd1eeca71594) 

![GitHub License](https://img.shields.io/github/license/niwciu/PUSHBUTTON_SWITCH_LIB) ![GitHub top language](https://img.shields.io/github/languages/top/niwciu/PUSHBUTTON_SWITCH_LIB) ![GitHub Release](https://img.shields.io/github/v/release/niwciu/PUSHBUTTON_SWITCH_LIB) ![CI PiPeline](https://github.com/niwciu/PUSHBUTTON_SWITCH_LIB/actions/workflows/CI_Pipeline.yml/badge.svg)

<b><a href='https://niwciu.github.io/PUSHBUTTON_SWITCH_LIB/reports/CCR/JSON_ALL/HTML_OUT/project_coverage.html'>Library GCOVR Report</a></b>  
<b><a href='https://niwciu.github.io/PUSHBUTTON_SWITCH_LIB/reports/CCM/index.html'>Library Code Complexity Report</a></b>  <br><br>
<b><a href='https://niwciu.github.io/PUSHBUTTON_SWITCH_LIB/doc/lib_doc/html/index.html'>Doxygen Code Documentation </a></b> 


The `PUSHBUTTON_SWITCH_LIB` is a simple cross-platform C library providing interfaces for pushbuttons and two-state switches (two-state input signals).

## Features  
### Push Buttons:
- 3 trigger modes:
  - TRIGGER_ON_PUSH
  - TRIGGER_ON_RELEASE
  - TRIGGER_ON_SHORT_PUSH_AND_LONG_PUSH
- Option to enable repetition
- Fully configurable time slots for:
  - debounce time
  - time to the first repetition
  - time between continuous repetitions
  - time defining the difference between short and long push
- Option to dynamically register callbacks for each trigger source
- Driver interface that is fully separated from the driver layer

### Switches:
- Debounce functionality based on a repeat count of the same state (no timer needed)
- Fully configurable debounce counter
- Dynamically register callbacks for switch ON and OFF states
- Driver interface that is fully separated from the driver layer

## Examples, how to use library etc.

For more information about usage, examples, colaboration and all features please refer to [project wiki](https://github.com/niwciu/PUSHBUTTON_SWITCH_LIB/wiki)

<div align="center">

***
![myEmbeddedWayBanerWhiteSmaller](https://github.com/user-attachments/assets/f4825882-e285-4e02-a75c-68fc86ff5716)
***
</div>
