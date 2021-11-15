# KSN 2021 Problem Repository

Problem repository of **KSN 2021** (also known internationally as
**TOKI KSN Open Contest 2021**).

## Problems

| Alias | Slug                  | Title (id)         | Title (en)       | Type        |
| ----- | --------------------- | ------------------ | ---------------- | ----------- |
| 0A    | `ksn-2021-karakter`   | Karakter Mandiri   | Self Character   | batch       |
| 0B    | `ksn-2021-sandi`      | Sandi Biner        | Binary Cipher    | batch       |
| 0C    | `ksn-2021-hitung`     | Menghitung Bola    | Counting Balls   | interactive |
| 1A    | `ksn-2021-pertahanan` | Pertahanan Mandiri | Self Defence     | batch       |
| 1B    | `ksn-2021-lautan`     | Lautan Biner       | Binary Sea       | batch       |
| 1C    | `ksn-2021-warna`      | Mewarnai Bola      | Colouring Balls  | interactive |
| 2A    | `ksn-2021-permutasi`  | Permutasi Biner    | Self Permutation | batch       |
| 2B    | `ksn-2021-daratan`    | Daratan Biner      | Binary Land      | batch       |
| 2C    | `ksn-2021-roket`      | Mengirim Bola      | Delivering Balls | batch       |

## Credits

| Slug                  | Problem Author(s)                            |
| --------------------- | -------------------------------------------- |
| `ksn-2020-karakter`   | Abdul Malik Nurrokhman                       |
| `ksn-2020-sandi`      | Abdul Malik Nurrokhman                       |
| `ksn-2020-hitung`     | Vio Albert Ferdinand                         |
| `ksn-2020-pertahanan` | Ashar Fuadi                                  |
| `ksn-2020-lautan`     | Prabowo                                      |
| `ksn-2020-warna`      | Abdul Malik Nurrokhman                       |
| `ksn-2020-permutasi`  | Steven Novaryo                               |
| `ksn-2020-daratan`    | Pikatan Arya Bramajati, Scientific Committee |
| `ksn-2020-roket`      | Abdul Malik Nurrokhman                       |

## Upsolving

The problem statements and upsolving are available
[on TLX](https://tlx.toki.id/problems/ksn-2021).

The editorial can also be found on the same link

## Problem Structure Repository

Each problem contains a problem directory root (e.g. `ksn-2021-pertahanan/`).
A problem directory root contains the following files and directories:

* ID problem description (`description-id.html`)
* EN problem description (`description-en.html`)
* Model solution (`solution.cpp`)
* Subtasks solution (`solution-{subtask_number}.cpp`)
* Test case generator (`spec.cpp`)
* Configuration file (`config.json`)
* Alternative solutions (`solution_{author}_{verdict}_{solution-name}.cpp`)
* Render directory (`render/`)
* Helper directory (`helper/`)
* Communicator (`communicator.cpp`)
* Output validator (`scorer.cpp`)

### ID problem description

Problem description in English language.
The HTML file uses [Katex](https://katex.org/) syntax to render the math equations.

### EN problem description

Problem description in Bahasa Indonesia.

### Model solution

The solution used to generate the test cases.

### Subtasks solution

Solutions that are used for the purpose of testing the subtasks.

### Test case generator

Test case generator using [tcframe](http://tcframe.toki.id/en/stable/) v1.6.0.

### Configuration file

Contains a JSON object that may help with the automation to choose the correct settings in online judges.
Possible configs in this file:

* `time_limit` (number in ms)
* `memory_limit` (number in kB)
* `samples` (a list of lists that maps a sample to its subtasks)
* `test_groups` (a list of lists that maps test group to its subtasks)
* `points` (a list containing the points of each subtask)
* `interactive` (a boolean).

### Alternative solutions

Several alternative and wrong solutions for the purpose of testing.

### Render directory

Contains the assets that is used by the HTML description file.
Usually contains images.

### Helper directory

May contain scripts that help with problem preparation or the raw files of the assets in `render/`.

### Communicator

For communication in interactive problem using [tcframe format](https://tcframe.toki.id/en/stable/topic-guides/styles.html#communicator)

### Output validator

To validate solutions which do not use exact match (may contain multiple solutions or require precision handling) using [tcframe format](https://tcframe.toki.id/en/stable/topic-guides/styles.html#scorer).

## License

All tasks and materials are published under the [Creative Commons Attribution
(CC-BY)](https://github.com/ia-toki/ksn-2021/blob/master/LICENSE) License.
