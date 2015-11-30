.globl _asm_matQuad
.code 32

;# Multiplies a two matrices and writes the result to destination. Assumes that all matrices are 8x8.
;# void _asm_matQuad(float* m1, float* m2, float* dest)

_asm_matQuad:
push {fp, lr}

nop

pop {fp,pc}
