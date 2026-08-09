import { z } from 'zod';
import { Board } from '@prisma/client';
import { CreateBoard } from './schema';
import { ActionState } from '@/lib/create-safe-action';

export type InputType = z.infer<typeof CreateBoard>;
export type ReturnType = ActionState<InputType, Board>;