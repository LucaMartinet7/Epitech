"use server";

import { auth } from "@clerk/nextjs/server";
import { InputType, ReturnType } from "./types";
import { db } from "@/lib/db";
import { revalidatePath } from "next/cache";
import { createSafeAction } from "@/lib/create-safe-action";
import { UpdateListOrder } from "./schema";

const handler = async (data: InputType): Promise<ReturnType> => {
    const { userId, orgId} = auth();

    if (!userId || !orgId) {
        return {
            error: "You must be logged in to update a board",
        } as ReturnType;
    }

    const { items, boardId } = data;
    let lists;

    try {
        const transaction = items.map((list) => db.list.update({
            where: {
                id: list.id,
                board: {
                    orgId,
                },
            },
            data: {
                order: list.order,
            },
        }));
        lists = await db.$transaction(transaction);
    } catch {
        return {
            error: "failed to reorder list",
        }
    }
    revalidatePath(`/board/${boardId}`);
    return { data: lists };
}

export const updateListOrder = createSafeAction(UpdateListOrder, handler);