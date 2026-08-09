"use server";

import { createSafeAction } from "@/lib/create-safe-action";
import { db } from "@/lib/db";
import { auth } from "@clerk/nextjs/server";
import { revalidatePath } from "next/cache";
import { CreateBoard } from "./schema";
import { InputType, ReturnType } from "./types";

const handler = async (data: InputType): Promise<ReturnType> => {
    const { userId, orgId} = auth();

    if (!userId || !orgId) {
        return {
            error: "You must be logged in to create a board",
        } as ReturnType;
    }

    const { title } = data;
    const colour = data.color;

    let board;

    try {
        board = await db.board.create({
            data: {
                title,
                colorId: colour,
                orgId,
            },
        });
    } catch {
        return {
            error: "failed to create board",
        } as ReturnType;
    }

    revalidatePath(`/board/${board.id}`);
    return { data: board } as ReturnType;
}

export const createBoard = createSafeAction(CreateBoard, handler);