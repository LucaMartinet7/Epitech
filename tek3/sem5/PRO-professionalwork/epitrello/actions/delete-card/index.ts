"use server";

import { auth } from "@clerk/nextjs/server";
import { InputType, ReturnType } from "./types";
import { db } from "@/lib/db";
import { revalidatePath } from "next/cache";
import { createSafeAction } from "@/lib/create-safe-action";
import { DeleteCard } from "./schema";

const handler = async (data: InputType): Promise<ReturnType> => {
    const { userId, orgId} = auth();

    if (!userId || !orgId) {
        return {
            error: "You must be logged in to update a board",
        } as ReturnType;
    }

    const { id, boardId } = data;
    let card;

    try {
        card = await db.card.delete({
            where: {
                id,
                list: {
                    board: {
                        orgId,
                    },
                },
            },
        });
    } catch {
        return {
            error: "failed to delete card",
        }
    }
    revalidatePath(`/board/${boardId}`);
    return { data: card };
}

export const deleteCard = createSafeAction(DeleteCard, handler);