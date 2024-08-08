# PUSHBUTTON_SWITCH_LIB - simple C cross-platform library 
![keypad_lib](https://github.com/user-attachments/assets/d7c28488-53b3-46a1-956d-2e8736f214d3)
![GitHub License](https://img.shields.io/github/license/niwciu/PUSHBUTTON_SWITCH_LIB) ![GitHub top language](https://img.shields.io/github/languages/top/niwciu/PUSHBUTTON_SWITCH_LIB) ![GitHub Release](https://img.shields.io/github/v/release/niwciu/PUSHBUTTON_SWITCH_LIB) <a href='https://coveralls.io/github/niwciu/PUSHBUTTON_SWITCH_LIB?branch=feature/code_coverage_page_deploy'><img src='https://coveralls.io/repos/github/niwciu/PUSHBUTTON_SWITCH_LIB/badge.svg?branch=feature/code_coverage_page_deploy' alt='Coverage Status' /></a> ![Unit Tests](https://github.com/niwciu/PUSHBUTTON_SWITCH_LIB/actions/workflows/CI_CD_workflow.yml/badge.svg)

<b><a href='./reports/Code_Coverage/PUSHBUTTON/pushbutton_gcov_report.html'>PushButton GCOVR Report</a></b>  
<b><a href='./reports/Code_Coverage/PUSHBUTTON/pushbutton_gcov_report.html'>Switch GCOVR Report</a></b>   
<b><a href='./reports/Cyclomatic_Complexity/PUSHBUTTON/Lizard_report.html'>PushButton Code Complexity Report</a></b>   
<b><a href='https://coveralls.io/github/niwciu/PUSHBUTTON_SWITCH_LIB?branch=feature/code_coverage_page_deploy'>Switch Code Complexity Report</a></b>

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

***
![myEmbeddedWayBanerWhiteSmaller](https://github.com/user-attachments/assets/f4825882-e285-4e02-a75c-68fc86ff5716)
***

