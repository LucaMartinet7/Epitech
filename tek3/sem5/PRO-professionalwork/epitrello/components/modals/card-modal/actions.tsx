"use client";

import { Button } from "@/components/ui/button";
import { CardWithList } from "@/types";
import { useAction } from "@/hooks/use-action";
import { deleteCard } from "@/actions/delete-card";
import { useParams } from "next/navigation";
import { toast } from "sonner";

interface ActionsProps {
    data: CardWithList;
}

export const Actions = ({
    data,
}: ActionsProps) => {
    const params = useParams();
    const { execute: executeDeleteCard } = useAction(deleteCard, {
        onSuccess: () => {
            toast.success("Card deleted");
        },
    });

    const onDelete = () => {
        const boardId = params.boardId as string;

        executeDeleteCard({ id: data.id, boardId });
    }

    return (
        <div className="space-y-2 mt-2">
            <p className="text-md font-semibold ">
                Actions:
            </p>
            <Button className="h-4 mr-2" onClick={onDelete}>
                delete
            </Button>
        </div>
    );
}

export { useAction };
