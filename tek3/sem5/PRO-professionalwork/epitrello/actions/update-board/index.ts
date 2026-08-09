"use server";

import { auth } from "@clerk/nextjs/server";
import { InputType, ReturnType } from "./types";
import { db } from "@/lib/db";
import { revalidatePath } from "next/cache";
import { createSafeAction } from "@/lib/create-safe-action";
import { UpdateBoard } from "./schema";

const handler = async (data: InputType): Promise<ReturnType> => {
    const { userId, orgId} = auth();

    if (!userId || !orgId) {
        return {
            error: "You must be logged in to update a board",
        } as ReturnType;
    }

    const { title, id } = data;
    let board;

    try {
        board = await db.board.update({
            where: {
                id,
                orgId,
            },
            data: {
                title,
            },
        });
    } catch {
        return {
            error: "failed to update board",
        }
    }
    revalidatePath(`/board/${id}`);
    return { data: board };
}

export const updateBoard = createSafeAction(UpdateBoard, handler);