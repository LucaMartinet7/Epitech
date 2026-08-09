"use client";

import { ElementRef, useRef, useState } from "react";
import { Popover, PopoverTrigger, PopoverContent, PopoverClose } from "@/components/ui/popover";
import { useAction } from "@/hooks/use-action";
import { createBoard } from "@/actions/create-board";
import { toast } from "sonner";
import { X } from "lucide-react";
import { Button } from "../ui/button";
import { cn } from "@/lib/utils";
import { FormErrors } from "./form-errors";
import { FormSubmit } from "./form-submit";
import { FormInput } from "./form-input";
import { useRouter } from "next/navigation";

interface FormPopoverProps {
    children: React.ReactNode;
    side?: "left" | "right" | "top" | "bottom";
    align?: "start" | "center" | "end";
    sideOffset?: number;
}

interface FormPickerProps {
    id: string;
    errors?: Record<string, string[] | undefined>;
    onColorSelect: (color: string) => void;
}

const colors = [
    "#E63946", // Red
    "#F4A261", // Orange
    "#2A9D8F", // Teal
    "#264653", // Dark Blue
    "#457B9D", // Soft Blue
    "#1D3557", // Navy Blue
    "#A8DADC", // Light Teal
    "#F1FAEE", // Off White
    "#E9C46A", // Yellow
];

const FormPicker = ({ id, errors, onColorSelect }: FormPickerProps) => {
    const [selectedColor, setSelectedColor] = useState<string | null>(null);

    const handleColorSelect = (color: string) => {
        setSelectedColor(color);
        onColorSelect(color);
    };

    return (
        <div className="relative">
            <div className="grid grid-cols-3 gap-2 mb-2">
                {colors.map((color) => (
                    <div key={color}>
                        <div
                            className={cn(
                                "cursor-pointer relative aspect-square group hover:opacity-75 transition",
                                selectedColor === color && "ring-2 ring-offset-2 ring-blue-500"
                            )}
                            style={{ backgroundColor: color }}
                            onClick={() => handleColorSelect(color)}
                        />
                        <input type="radio" id={id} name={id} className="hidden" value={selectedColor || ''} />
                    </div>
                ))}
            </div>
            <FormErrors id={id} errors={errors} />
        </div>
    );
};

export const FormPopover = ({
    children,
    side = "bottom",
    align,
    sideOffset = 0,
}: FormPopoverProps) => {
    const router = useRouter();
    const closeRef = useRef<ElementRef<"button">>(null);

    const { execute, FieldErrors } = useAction(createBoard, {
        onSuccess: (data) => {
            console.log("Board created", data);
            toast.success("Board created successfully");
            closeRef.current?.click();
            router.push(`/board/${data.id}`);
        },
        onError: (error) => {
            console.error("Error creating board", error);
            toast.error("Error creating board");
        },
    });

    const [selectedColor, setSelectedColor] = useState<string | null>(null);

    const onSubmit = (formData: FormData) => {
        const title = formData.get("title") as string;
        const color = selectedColor || '';

        // console.log("Creating board", title, color);

        execute({ title, color });
    };

    return (
        <Popover>
            <PopoverTrigger asChild>
                {children}
            </PopoverTrigger>
            <PopoverContent align={align} className="w-80 pt-3" side={side} sideOffset={sideOffset}>
                <div className="text-sm font-medium text-center text-neutral-600 pb-4">
                    create Board
                </div>
                <PopoverClose ref={closeRef} asChild>
                    <div className="absolute top-2 right-2">
                        <Button className="h-auto w-auto p-2absolute top-2 right-2 text-neutral-600" variant="ghost">
                            <X className="h-4 w-4" />
                        </Button>
                    </div>
                </PopoverClose>
                <form action={onSubmit} className="space-y-4">
                    <div className="space-y-4">
                        <FormPicker id="color" errors={FieldErrors} onColorSelect={setSelectedColor} />
                        <FormInput id="title" label="Board Title" type="text" errors={FieldErrors} />
                    </div>
                    <FormSubmit className="w-full">
                        Create Board
                    </FormSubmit>
                </form>
            </PopoverContent>
        </Popover>
    );
};